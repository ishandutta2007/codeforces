#include<bits/stdc++.h>
using namespace std;

struct var{
    long long cnt;
    string pre,suf;
    int count(const string &s){
        int res=0;
        for(int i=0;i+3<s.size();i++){
            res+=s.substr(i,4)=="haha";
        }
        return res;
    }
    var(const string &s){
        cnt=count(s);
        pre=s.substr(0,min((int)s.size(),3));
        suf=s.substr(max(0,(int)s.size()-3),min(3,(int)s.size()));
    }
    var(){
        cnt=0;
    }
    void join(var a,var b){
        cnt=a.cnt+b.cnt+count(a.suf+b.pre);
        pre=a.pre+b.pre;
        pre=pre.substr(0,min((int)pre.size(),3));
        suf=a.suf+b.suf;
        suf=suf.substr(max(0,(int)suf.size()-3),min(3,(int)suf.size()));
    }
};

void mian(){
    map<string,var> v;
    int n;
    cin>>n;
    string a,b,c,buf;
    while(n--){
        cin>>a>>buf;
        if(buf==":="){
            cin>>b;
            v[a]=var(b);
        }else{
            cin>>b>>buf>>c;
            v[a].join(v[b],v[c]);
        }
    }
    cout<<v[a].cnt<<'\n';
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--)mian();

    return 0;
}