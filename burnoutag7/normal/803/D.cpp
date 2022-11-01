#include<bits/stdc++.h>
using namespace std;

int n,k;
int a[1000005];
string s;

bool chk(int x){
    int cur=0,cnt=0;
    for(int i=0;i<n;i++){
        if(a[i]>x)return false;
        cur+=a[i];
        if(cur>x){
            cur=a[i];
            cnt++;
        }
    }
    if(cur)cnt++;
    return cnt<=k;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>k;
    getline(cin,s);
    getline(cin,s);s+=' ';
    int pos=-1;
    for(int i=0;i<s.size();i++){
        if(s[i]==' '||s[i]=='-'){
            a[n++]=i-pos;
            pos=i;
        }
    }
    a[n-1]--;
    int l=1,r=1000000,m,ans;
    while(l<=r){
        m=(l+r)/2;
        if(chk(m)){
            ans=m;
            r=m-1;
        }else{
            l=m+1;
        }
    }
    cout<<ans<<endl;

    return 0;
}