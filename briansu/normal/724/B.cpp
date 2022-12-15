#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
const double EPS=1e-8;
const ll INF=ll(1e18);
const int sINF=int(1e8);
typedef pair<int,int> ii;
typedef set<int>::iterator isit;
struct p
{
    int x,y;
    p(int x,int y){this->x=x;this->y=y;}
    bool operator ==(const p &b)const
    {
        return (b.x==x&&b.y==y)||(b.x==y&&b.y==x);
    }
    bool operator ==(const ii &b)const
    {
        return b.first==x||b.second==x||b.first==y||b.second==y;
    }
    bool operator <(const p &b)const
    {
        return (b.x+b.y<x+y);
    }

};
set<p> uni(set<p> a,set<p> b)
{
    set<p> r;
    for(set<p>::iterator it=a.begin();it!=a.end();it++)
    {
        for(set<p>::iterator it2=b.begin();it2!=b.end();it2++)
        {
            if((*it)==(*it2)){r.insert(*it);break;}
        }
    }
    return r;
}
set<p> uni(set<p> a,ii b)
{
    set<p> r;
    for(set<p>::iterator it=a.begin();it!=a.end();it++)
    {
        if((*it)==b){r.insert(*it);break;}
    }
    return r;
}
int main()
{
    bool pr=true,two=true;
    int r,c;
    cin>>r>>c;
    int num[r];
    fill(num,num+r,0);
    int data[r][c];
    vector<int> tc[r];
    vector<ii> mt;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cin>>data[i][j];
            if(data[i][j]!=j+1)
            {
                num[i]++;
                tc[i].push_back(j);
            }
        }
        if(num[i]>4)pr=false;
        else if(num[i]==4&&data[i][data[i][tc[i][0]]-1]!=tc[i][0]+1)pr=false;
        if(num[i]>2)two=false;
        //cout<<num[i]<<" "<<pr<<endl;
    }

    set<p> s;
    bool st=false;
    for(int i=0;i<r&&pr&&!two;i++)
    {
        if(st)
        {
            set<p> tmp;
            if(num[i]==0)continue;
            if(num[i]==2)
            {
                tmp.insert(p(tc[i][0],tc[i][1]));
                //mt.push_back(ii(tc[i][0],tc[i][1]));
                //continue;
            }
            else if(num[i]==3)
            {
                tmp.insert(p(tc[i][0],tc[i][1]));
                tmp.insert(p(tc[i][0],tc[i][2]));
                tmp.insert(p(tc[i][1],tc[i][2]));
            }
            else if(num[i]==4)
            {
                if(data[i][tc[i][0]]-1==tc[i][1])
                {
                    tmp.insert(p(tc[i][0],tc[i][1]));
                    tmp.insert(p(tc[i][2],tc[i][3]));
                }
                else if(data[i][tc[i][0]]-1==tc[i][2])
                {
                    tmp.insert(p(tc[i][0],tc[i][2]));
                    tmp.insert(p(tc[i][1],tc[i][3]));
                }
                else
                {
                    tmp.insert(p(tc[i][0],tc[i][3]));
                    tmp.insert(p(tc[i][1],tc[i][2]));
                }
            }
            s=uni(s,tmp);
            if(s.empty())pr=false;
        }
        else
        {
            if(num[i]==2)
            {
                //mt.push_back(ii(tc[i][0],tc[i][1]));
                s.insert(p(tc[i][0],tc[i][1]));
                st=true;
            }
            else if(num[i]==3)
            {
                s.insert(p(tc[i][0],tc[i][1]));
                s.insert(p(tc[i][0],tc[i][2]));
                s.insert(p(tc[i][1],tc[i][2]));
                st=true;
            }
            else if(num[i]==4)
            {
                if(data[i][tc[i][0]]-1==tc[i][1])
                {
                    s.insert(p(tc[i][0],tc[i][1]));
                    s.insert(p(tc[i][2],tc[i][3]));
                }
                else if(data[i][tc[i][0]]-1==tc[i][2])
                {
                    s.insert(p(tc[i][0],tc[i][2]));
                    s.insert(p(tc[i][1],tc[i][3]));
                }
                else
                {
                    s.insert(p(tc[i][0],tc[i][3]));
                    s.insert(p(tc[i][1],tc[i][2]));
                }
                st=true;
            }
        }
    }
    if(pr)
    {
//        if(st)
//        {
//            for(int i=0;i<mt.size();i++)
//            {
//                s=uni(s,mt[i]);
//                if(s.empty()){cout<<"NO"<<endl;return 0;}
//            }
//        }
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
}