#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    int n,k;
    char a[50];
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    int ans=0;
    char pre;
    ans=a[0]-'a'+1;
    int cnt=1;
    pre=a[0];
    for(int i=0;i<n;i++)
    {
        if(a[i]-pre>1)
        {
            pre=a[i];
            cnt++;
            ans+=a[i]-'a'+1;
        }
        if(cnt==k) break;
    }
    if(cnt<k)
        cout<<-1<<endl;
    else cout<<ans<<endl;
    return 0;
}