#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int N=100010;
const int bas=211;
unsigned long long ha[N],mi[N];
int num[N][26];
int a[N];
int n,len[30];
bool gray[N][30];
long long val[N][26],cost[N],ans;
int maxlog;
char s[N];
bool pan(int l1,int l2,int le)
{
    int r1=l1+le-1,r2=l2+le-1;
    if (r1>n||r2>n) return 0;
    unsigned long long s1=ha[r1]-ha[l1-1]*mi[r1-l1+1];
    unsigned long long s2=ha[r2]-ha[l2-1]*mi[r2-l2+1];
    return s1==s2;
}
void judge(int l,int k)
{
    if (k==1) {gray[l][k]=1;return;}
    int mid=l+len[k-1],r=l+len[k]-1;
    if ((num[r][a[mid]]-num[l-1][a[mid]]==1)&&pan(l,mid+1,len[k-1])&&gray[l][k-1]&&gray[mid+1][k-1])
        gray[l][k]=1;
    return;
}
int LCP(int l1,int l2)
{
    int le=0;
    for (int i=maxlog;i>=0;i--)
        if (pan(l1+le,l2+le,(1<<i))) le+=(1<<i);
    return le;
}
void calc(int l,int k)
{
    int r=l+len[k]-1,mid=l+len[k-1];
    if (k==1) {for (int i=0;i<26;i++) if (a[l]!=i) val[l][i]++;return;}
    if (pan(l,mid+1,len[k-1])&&gray[l][k-1]&&gray[mid+1][k-1])
    {
        for (int i=0;i<26;i++)
            if (a[mid]!=i&&num[r][i]-num[l-1][i]==0) val[mid][i]+=1ll*len[k]*len[k];
    }
    int l1=l,l2=mid+1;
    int lcp=LCP(l1,l2);
    if (lcp>=len[k-1]) return;
    if (l1+lcp+1+LCP(l1+lcp+1,l2+lcp+1)<mid) return;
    if (gray[l2][k-1]&&num[r][a[mid]]-num[mid][a[mid]]==0) val[l1+lcp][a[l2+lcp]]+=1ll*len[k]*len[k];
    if (gray[l1][k-1]&&num[mid-1][a[mid]]-num[l-1][a[mid]]==0) val[l2+lcp][a[l1+lcp]]+=1ll*len[k]*len[k];
}
int main()
{
    scanf("%s",s+1);
    n=strlen(s+1);
    mi[0]=1;
    for (int i=1;i<=n;i++)
    {
        a[i]=s[i]-'a';
        num[i][a[i]]++;
        for (int j=0;j<26;j++) num[i][j]+=num[i-1][j];
        mi[i]=mi[i-1]*bas;
        ha[i]=ha[i-1]*bas+s[i];
    }
    for (int i=1;i<=30;i++)
    {
        len[i]=len[i-1]*2+1;
        if (len[i]>n) {maxlog=i-1;break;}
    }
    for (int i=1;i<=maxlog;i++)
        for (int j=1;j<=n;j++)
        {
            if (j+len[i]-1>n) break;
            judge(j,i);
            if (gray[j][i]) ans+=1ll*len[i]*len[i],cost[j]+=1ll*len[i]*len[i],cost[j+len[i]]-=1ll*len[i]*len[i];
        }
    for (int i=1;i<=n;i++) cost[i]+=cost[i-1];
    for (int i=1;i<=maxlog;i++)
        for (int j=1;j<=n;j++)
        {
            if (j+len[i]-1>n) break;
            calc(j,i);
        }
    long long sum=0;
    for (int j=1;j<=n;j++)
        for (int k=0;k<26;k++)
            sum=max(sum,-cost[j]+val[j][k]);
    printf("%I64d",sum+ans);
}