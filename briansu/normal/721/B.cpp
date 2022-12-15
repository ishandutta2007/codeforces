#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
const double EPS=1e-8;
const ll INF=ll(1e18);
int main()
{
    int cnt[101];
    memset(cnt,0,sizeof(cnt));
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        string tmp;
        cin>>tmp;
        cnt[tmp.length()]++;
    }
    string ans;
    cin>>ans;
    int len=ans.length();
    int sum=0;
    for(int i=1;i<len;i++)
    {
        sum+=cnt[i];
    }
    int mi=sum+int(sum/k)*5+1;
    sum+=cnt[len];
    int ma=sum+int((sum-1)/k)*5;
    cout<<mi<<" "<<ma<<endl;
}