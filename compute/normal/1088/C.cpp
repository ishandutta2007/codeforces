#include<bits/stdc++.h>
using namespace std;
const int maxn=2005;
int arr[maxn];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        arr[i]+=500000;
    }
    cout<<n+1<<endl;
    printf("1 %d 500000\n",n);
    for(int i=0;i<n;i++)
    {
        printf("2 %d %d\n",i+1,arr[i]-i);
    }
}