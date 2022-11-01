#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

bool is_op(char c){return (c=='+'||c=='?'||c=='*');}

string fix(string s)
{
    int n=s.size();
    string t;
    for(int i=0;i<n;i++)
    {
        if(i+1<n&&isupper(s[i])&&is_op(s[i+1])) t+="("+string(1,s[i])+")";
        else t+=s[i];
    }
    s=t;
    t.clear();
    n=s.size();
    int l=0;
    while(l<n)
    {
        if(!isupper(s[l]))
        {
            t+=s[l++];
            continue;
        }
        int r=l;
        while(r+1<n&&isupper(s[r+1])) r++;
        t+="("+s.substr(l,r-l+1)+")";
        l=r+1;
    }
    return "("+t+")";
}

struct obj
{
    int h=0,w=0;
    vector<string> v;
    void ini(){v.assign(h,string(w,' '));}
    void make_box(int r1,int c1,int r2,int c2,char up='|')
    {
        for(int r:{r1,r2}) for(int c:{c1,c2}) v[r][c]='+';
        for(int j=c1+1;j<c2;j++) v[r1][j]=v[r2][j]='-';
        for(int i=r1+1;i<r2;i++) v[i][c1]=v[i][c2]=up;
    }
    obj(string s)
    {
        int n=s.size();
        w=n+4;
        h=3;
        ini();
        make_box(0,0,h-1,w-1,'+');
        for(int j=2;j-2<n;j++) v[1][j]=s[j-2];
    }
    void cpy(obj o,int r,int c)
    {
        for(int i=0;i<o.h;i++) for(int j=0;j<o.w;j++) v[r+i][c+j]=o.v[i][j];
    }
    void join_horizontal(vector<obj> t)
    {
        for(obj o:t)
        {
            w+=(o.w+2);
            h=max(h,o.h);
        }
        w-=2;
        ini();
        int c=0;
        for(obj o:t)
        {
            cpy(o,0,c);
            c+=o.w;
            if(c+1<w)
            {
                v[1][c]='-';
                v[1][c+1]='>';
            }
            c+=2;
        }
    }
    void join_vertical(vector<obj> t)
    {
        for(obj o:t)
        {
            h+=(o.h+1);
            w=max(w,o.w);
        }
        h--;
        w+=6;
        ini();
        int r=0;
        for(obj o:t)
        {
            if(r+o.h+2<h) make_box(r+1,0,r+o.h+2,w-1);
            r+=(o.h+1);
        }
        r=0;
        for(obj o:t)
        {
            cpy(o,r,3);
            v[r+1][2]=v[r+1][w-2]='>';
            r+=(o.h+1);
        }
    }
    obj(vector<obj> t,int tp)
    {
        if(t.size()==1) (*this)=t[0];
        else if(tp==0) join_horizontal(t);
        else join_vertical(t);
    }
    void ini_plus(obj o)
    {
        h=o.h+2;
        w=o.w+6;
        ini();
        make_box(1,0,h-1,w-1);
        cpy(o,0,3);
        v[1][2]=v[1][w-2]='>';
        v[h-1][1]='<';
    }
    void ini_question(obj o)
    {
        h=o.h+3;
        w=o.w+6;
        ini();
        make_box(1,0,4,w-1);
        cpy(o,3,3);
        v[1][w-2]=v[4][2]=v[4][w-2]='>';
    }
    void ini_star(obj o)
    {
        h=o.h+5;
        w=o.w+6;
        ini();
        make_box(1,0,4,w-1);
        make_box(4,0,h-1,w-1);
        cpy(o,3,3);
        v[1][w-2]=v[4][2]=v[4][w-2]='>';
        v[h-1][1]='<';
    }
    void ini_final(obj o)
    {
        h=o.h;
        w=o.w+6;
        ini();
        cpy(o,0,3);
        string one="S->";
        for(int j=0;j<3;j++) v[1][j]=one[j];
        string two="->F";
        for(int j=w-3;j<w;j++) v[1][j]=two[j-(w-3)];
    }
    obj(obj o,char op)
    {
        if(op=='+') ini_plus(o);
        else if(op=='?') ini_question(o);
        else if(op=='*') ini_star(o);
        else if(op=='S') ini_final(o);
    }
    void print()
    {
        cout << h << " " << w << endl;
        for(string s:v) cout << s << endl;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    s=fix(s);
    int idx=0;
    function<obj()> go=[&]()->obj
    {
        vector<obj> h,v;
        string t;
        idx++;
        while(s[idx]!=')')
        {
            if(s[idx]=='(')
            {
                h.push_back(go());
            }
            else if(s[idx]=='|')
            {
                v.push_back(obj(h,0));
                h.clear();
            }
            else if(isupper(s[idx])) t+=s[idx];
            else if(is_op(s[idx])) h.back()=obj(h.back(),s[idx]);
            idx++;
        }
        if(!t.empty()) h.push_back(obj(t));
        v.push_back(obj(h,0));
        return obj(v,1);
    };
    obj r(go(),'S');
    r.print();
    return 0;
}