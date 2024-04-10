#include<bits/stdc++.h>
using namespace std;

struct automata{
    vector<string> g;
    int ir;
    automata(){}
    automata(const string &s){
        string t(s.size(),'-');
        ir=1;
        g={"+-"+t+"-+","+ "+s+" +","+-"+t+"-+"};
    }
    automata(const vector<automata> &v){
        if(v.size()==1){
            *this=v[0];
            return;
        }
        int totr=v.size()-1,totc=0;
        for(auto &a:v){
            totr+=a.g.size();
            totc=max(totc,(int)a.g[0].size()+6);
        }
        g.resize(totr,string(totc,' '));
        for(int i=v[0].ir;i-v.back().ir+v.back().g.size()<=totr;i++)g[i][0]=g[i].back()='|';
        int p=0;
        for(auto &a:v){
            for(int i=0;i<a.g.size();i++)for(int j=0;j<a.g[0].size();j++){
                g[i+p][j+3]=a.g[i][j];
            }
            g[a.ir+p][0]='+';g[a.ir+p][1]='-';g[a.ir+p][2]='>';
            g[a.ir+p][totc-1]='+';g[a.ir+p][totc-2]='>';
            for(int i=a.g[0].size()+3;i<totc-2;i++)g[a.ir+p][i]='-';
            p+=a.g.size()+1;
        }
        ir=v[0].ir;
    }
    automata operator+(const automata &a)const{
        if(g.empty())return a;
        if(a.g.empty())return *this;
        automata res;
        res.ir=max(ir,a.ir);
        res.g.resize(res.ir+max(g.size()-ir,a.g.size()-a.ir),string(g[0].size()+a.g[0].size()+2,' '));
        res.g[res.ir][g[0].size()]='-';
        res.g[res.ir][g[0].size()+1]='>';
        for(int i=0;i<g.size();i++)for(int j=0;j<g[0].size();j++)res.g[i-ir+res.ir][j]=g[i][j];
        for(int i=0;i<a.g.size();i++)for(int j=0;j<a.g[0].size();j++)res.g[i-a.ir+res.ir][j+g[0].size()+2]=a.g[i][j];
        return res;
    }
    automata op(char c)const{
        automata res;
        res.ir=ir+(c!='+'?3:0);
        res.g.resize(g.size()+(c=='+'?2:c=='?'?3:5),string(g[0].size()+6,' '));
        for(int i=0;i<g.size();i++)for(int j=0;j<g[0].size();j++)res.g[i-ir+res.ir][j+3]=g[i][j];
        res.g[res.ir][0]='+';res.g[res.ir][1]='-';res.g[res.ir][2]='>';
        res.g[res.ir][g[0].size()+3]='-';res.g[res.ir][g[1].size()+4]='>';res.g[res.ir][g[2].size()+5]='+';
        if(c!='?'){
            for(int i=res.ir+1;i+1<res.g.size();i++)res.g[i][0]=res.g[i].back()='|';
            res.g.back()[0]='+';res.g.back()[1]='<';res.g.back().back()='+';
            for(int i=2;i+1<res.g[0].size();i++)res.g.back()[i]='-';
        }
        if(c!='+'){
            for(int i=2;i<res.ir;i++)res.g[i][0]=res.g[i].back()='|';
            res.g[1][0]='+';res.g[1][res.g[0].size()-2]='>';res.g[1].back()='+';
            for(int i=1;i+2<res.g[0].size();i++)res.g[1][i]='-';
            res.ir=1;
        }
        return res;
    }
};

ostream& operator<<(ostream &o,const automata &a){
    o<<a.g.size()<<' '<<a.g[0].size()+6<<'\n';
    for(int i=0;i<a.g.size();i++)o<<(i==a.ir?"S->":"   ")<<a.g[i]<<(i==a.ir?"->F\n":"   \n");
    return o;
}

automata expr(const string &s);

automata term(const string &s){
    if(s[0]=='('){
        for(int i=0,h=0;i<s.size();i++){
            h+=(s[i]=='(')-(s[i]==')');
            if(!h){
                if(i+1==s.size())return expr(s.substr(1,s.size()-2));
                else break;
            }
        }
    }
    automata res;
    stack<char> op;
    for(int i=s.size()-1;i>=0;i--){
        if(s[i]=='+'||s[i]=='?'||s[i]=='*'){
            op.emplace(s[i]);
            continue;
        }
        automata cur;
        if(s[i]==')'){
            int j=i,h=1;
            while(h){
                j--;
                h+=(s[j]==')')-(s[j]=='(');
            }
            cur=expr(s.substr(j,i-j+1));
            i=j;
        }else{
            if(!op.empty())cur=automata(s.substr(i,1));
            else{
                int j=i;
                while(j&&isalpha(s[j-1]))j--;
                cur=automata(s.substr(j,i-j+1));
                i=j;
            }
        }
        while(!op.empty()){
            cur=cur.op(op.top());
            op.pop();
        }
        res=cur+res;
    }
    return res;
}

automata expr(const string &s){
    vector<int> sep;
    for(int i=0,h=0;i<s.size();i++){
        h+=(s[i]=='(')-(s[i]==')');
        if(!h&&s[i]=='|')sep.emplace_back(i);
    }
    vector<automata> v;
    int p=0;
    for(int i=0;i<sep.size();i++){
        v.emplace_back(term(s.substr(p,sep[i]-p)));
        p=sep[i]+1;
    }
    v.emplace_back(term(s.substr(p)));
    return automata(v);
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin>>s;
    cout<<expr(s);

    return 0;
}