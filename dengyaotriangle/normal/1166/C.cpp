#include<bits/stdc++.h>

using namespace std;

const int maxn=200005;

int n;
int a[maxn];

int main(){
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        int t;
        cin>>t;
        if(t<0) t=-t;
        a[i]=t;
    }
    int cp=0;
    sort(a+1,a+1+n);
    long long ans=0;
    for(int i=1;i<=n;i++){
        while(cp!=n&&a[cp+1]<=2*a[i])cp++;
        ans+=cp-i;
    }
    cout<<ans;
    return 0;
}