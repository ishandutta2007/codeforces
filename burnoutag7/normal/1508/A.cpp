#include<bits/stdc++.h>
using namespace std;

int f[200005],nxt[200005][2];

string get(string &s,string &t,int n){
    static string res;
    for(char bs='0';bs<='1';bs++){
        res.clear();
        int cs=0,ct=0;
        for(int i=0;i<2*n;i++){
            cs+=s[i]==bs;ct+=t[i]==bs;
        }
        vector<int> v(max(cs,ct)+1);
        cs=ct=0;
        int ccs=0,cct=0;
        for(int i=0;i<2*n;i++){
            if(s[i]==bs){
                cs++;
                ccs=0;
            }else v[cs]=max(v[cs],++ccs);
            if(t[i]==bs){
                ct++;
                cct=0;
            }else v[ct]=max(v[ct],++cct);
        }
        int tot=v.size()-1;
        for(int x:v)tot+=x;
        if(tot<=3*n){
            string r;
            for(int x:v)r+=string(x,bs^1)+bs;
            r.pop_back();
            return r;
        }
    }
    return "";
}

void mian(){
    int n;
    cin>>n;
    string s1,s2,s3,t;
    cin>>s1>>s2>>s3;
    if((t=get(s1,s2,n))!="")cout<<t<<'\n';
    else if((t=get(s1,s3,n))!="")cout<<t<<'\n';
    else cout<<get(s3,s2,n)<<'\n';
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