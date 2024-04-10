#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=100005;
const int mdn=998244353;

int n;
int a[maxn];
int cnt[maxn],lb[maxn],rb[maxn];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<=n;i++)cnt[i]=0,lb[i]=rb[i]=a[i];
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=i-1;j>=1;j--){
                bool typ=0;
                while(rb[j]>lb[j+1]){
                    int w=(a[j]-1)/(rb[j]-1)-cnt[j];
                    //cerr<<cnt[j]<<','<<w<<' '<<rb[j]<<"->"<<(a[j]+cnt[j]+w)/(cnt[j]+w+1)<<endl;
                    cnt[j]+=w;
                    lb[j]=a[j]/(cnt[j]+1);
                    rb[j]=(a[j]+cnt[j])/(cnt[j]+1);
                    ans=(ans+w*(long long)(n-i+1)%mdn*(long long)j)%mdn;
                    typ=1;
                }
                if(!typ)break;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}