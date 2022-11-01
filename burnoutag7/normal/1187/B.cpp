#include<bits/stdc++.h>
using namespace std;

struct LETTER{
    int occur[26];
};

bool cmp(LETTER a,LETTER b){
    for(int i=0;i<26;i++){
        if(a.occur[i]<b.occur[i])return false;
    }
    return true;
}

int n,m;
string s,t;
LETTER oc[200005];

int func(LETTER fnd){
    int l=0,r=n-1,m,ans;
    while(l<=r){
        m=(l+r)/2;
        if(cmp(oc[m],fnd)){
            ans=m;
            r=m-1;
        }else{
            l=m+1;
        }
    }
    return ans;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>s;
    oc[0].occur[s[0]-'a']++;
    for(int i=1;i<n;i++){
        for(int j=0;j<26;j++){
            oc[i].occur[j]=oc[i-1].occur[j];
        }
        oc[i].occur[s[i]-'a']++;
    }
    cin>>m;
    for(int i=1;i<=m;i++){
        cin>>t;
        LETTER cur;
        memset(cur.occur,0,sizeof(cur.occur));
        for(int j=0;j<t.size();j++){
            cur.occur[t[j]-'a']++;
        }
        cout<<func(cur)+1<<endl;
    }

    return 0;
}