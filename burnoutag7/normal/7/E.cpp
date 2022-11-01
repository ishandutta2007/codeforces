#include<bits/stdc++.h>
using namespace std;

int n;
vector<string> expr[105];
int prio[105];
map<string,int> def;

inline bool valid(int lp,char op,int rp){
    if(op=='/')return lp<=1&&rp<=0;
    if(op=='*')return lp<=1&&rp<=1;
    if(op=='+')return lp<=2&&rp<=2;
    if(op=='-')return lp<=2&&rp<=1;
    //cerr<<"OP INVALID"<<endl;
    return false;
}

int dfs(int id);

inline bool isnumber(const string &s){
    for(int i=0;i<s.size();i++){
        if(s[i]<'0'||s[i]>'9')return false;
    }return true;
}

inline bool ismacro(const string &s){
    return def.find(s)!=def.end();
}

inline bool isvalue(const string &s){
    for(int i=0;i<s.size();i++){
        if(!isalpha(s[i]))return false;
    }return true;
}

int parse(const vector<string> &v,int l,int r){
    if(l>=r)return 0;
    if(l+1==r){
        if(isnumber(v[l])){
            return 0;
        }
        if(ismacro(v[l])){
            return dfs(def[v[l]]);
        }
        if(isvalue(v[l])){
            return 0;
        }
        //cerr<<"PARSING: "<<v[l]<<endl;
        //cerr<<"PARSE INVALID"<<endl;
        return -1;
    }
    if(v[l]=="("&&v[r-1]==")"){
        bool f=true;
        int bkc=0;
        for(int i=l;i<r;i++){
            if(v[i]=="(")bkc++;
            if(v[i]==")")bkc--;
            if(bkc==0&&i+1!=r){
                f=false;
                break;
            }
        }
        if(f){
            parse(v,l+1,r-1);
            return 0;
        }
    }
    int bkc=0;
    for(int i=r-1;i>=l;i--){
        if(v[i]==")")bkc++;
        if(v[i]=="(")bkc--;
        if(bkc)continue;
        if(v[i]=="+"){
            if(valid(parse(v,l,i),'+',parse(v,i+1,r))){
                return 2;
            }else{
                cout<<"Suspicious"<<endl;
                exit(0);
            }
        }
        if(v[i]=="-"){
            if(valid(parse(v,l,i),'-',parse(v,i+1,r))){
                return 2;
            }else{
                cout<<"Suspicious"<<endl;
                exit(0);
            }
        }
    }
    for(int i=r-1;i>=l;i--){
        if(v[i]==")")bkc++;
        if(v[i]=="(")bkc--;
        if(bkc)continue;
        if(v[i]=="*"){
            if(valid(parse(v,l,i),'*',parse(v,i+1,r))){
                return 1;
            }else{
                cout<<"Suspicious"<<endl;
                exit(0);
            }
        }
        if(v[i]=="/"){
            if(valid(parse(v,l,i),'/',parse(v,i+1,r))){
                return 1;
            }else{
                cout<<"Suspicious"<<endl;
                exit(0);
            }
        }
    }
    //cerr<<"PARSING: "<<l<<' '<<r<<endl;
    //cerr<<"PARSE INVALID"<<endl;
    return -1;
}

int dfs(int id){
    //cerr<<"DFSING IN: "<<id<<endl;cerr<<prio[id]<<endl;
    if(prio[id]!=-1)return prio[id];
    return prio[id]=parse(expr[id],0,expr[id].size());
}

vector<string> mkexp(const string &s){
    vector<string> res;
    for(int i=0;i<s.size();i++){
        if(s[i]==' '){
            continue;
        }
        if(s[i]=='('){
            res.push_back("(");
            continue;
        }
        if(s[i]==')'){
            res.push_back(")");
            continue;
        }
        if(s[i]=='+'){
            res.push_back("+");
            continue;
        }
        if(s[i]=='-'){
            res.push_back("-");
            continue;
        }
        if(s[i]=='*'){
            res.push_back("*");
            continue;
        }
        if(s[i]=='/'){
            res.push_back("/");
            continue;
        }
        string tmp;
        int j;
        for(j=i;j<s.size()&&(isalpha(s[j])||(s[j]>='0'&&s[j]<='9'));j++){
            tmp+=s[j];
        }
        res.push_back(tmp);
        i=j-1;
    }
    return res;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    {
        string s,t;char c;
        getline(cin,s);
        for(int i=1;i<=n;i++){
            cin>>c>>s>>s;
            def[s]=i;
            getline(cin,t);
            //cerr<<s<<' '<<t<<endl;
            expr[i]=mkexp(t);
        }
        getline(cin,t);
        //cerr<<t<<endl;
        expr[0]=mkexp(t);
    }
    memset(prio,-1,sizeof(prio));
    dfs(0);
    cout<<"OK"<<endl;

    return 0;
}