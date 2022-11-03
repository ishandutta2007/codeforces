#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <complex>
#include <ctime>

using namespace std;

char str[100005],a[200005],b[200005];

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    gets(str);
    int cnt[10]={0},n=strlen(str);
    for(int i=0;i<n;i++)
        cnt[str[i]-'0']++;
    int mx=0,ii=1;
    for(int i=1;i<10;i++)
        if (cnt[i]) ii=i;
    for(int i=1;i<10;i++)
    {
        int cur=0,cnt1[10]={0},cnt2[10]={0};
        for(int j=0;j<10;j++) cnt2[j]=cnt1[j]=cnt[j];
        if (!cnt1[i]||!cnt2[(10-i)%10]) continue;
        cnt1[i]--,cnt2[(10-i)%10]--; cur=1;
        for(int j=0;j<10;j++)
            cur+=min(cnt1[j],cnt2[9-j]);
        cur+=min(cnt1[0],cnt2[0]);
        if (cur>mx) mx=cur,ii=i;
    }
    bool ok=true;
    if (cnt[0]>mx)
    {
        mx=cnt[0],ok=false;
        for(int i=1;i<10;i++)
            if (cnt[i])
            {
                ii=i;
                break;
            }
    }
    for(int i=1;i<10;i++)
    {
        int cur=0,cnt1[10]={0},cnt2[10]={0};
        for(int j=0;j<10;j++) cnt2[j]=cnt1[j]=cnt[j];
        if (!cnt1[i]||!cnt2[(10-i)%10]) continue;
        cnt1[i]--,cnt2[(10-i)%10]--; cur=1+cnt1[0];
        for(int j=1;j<9;j++)
            cur+=min(cnt1[j],cnt2[9-j]);
        if (cur>=mx) mx=cur,ii=i,ok=false;
    }
    if (ii!=-1)
    {
        if (!ok)
        {
            int cur=0,cnt1[10]={0},cnt2[10]={0},ind=n-1;
            for(int j=0;j<10;j++) cnt2[j]=cnt1[j]=cnt[j];
            while(cnt1[0])
            {
                a[ind]=b[ind]='0'; ind--;
                cnt1[0]--; cnt2[0]--;
            }
            if (cnt1[ii]&&cnt2[(10-ii)%10])
            {
                a[ind]=ii+'0'; b[ind]=(10-ii)%10+'0'; ind--;
                cnt1[ii]--,cnt2[(10-ii)%10]--;
            }
            for(int j=1;j<9;j++)
            {
                int k=min(cnt1[j],cnt2[9-j]);
                for(int i=0;i<k;i++)
                {
                    a[ind]=j+'0'; b[ind]=9-j+'0'; ind--;
                    cnt1[j]--; cnt2[9-j]--;
                }
            }
            int ind1=ind;
            for(int i=1;i<10;i++)
                while(cnt1[i])
                {
                    a[ind]=i+'0'; ind--; cnt1[i]--;
                }
            ind=ind1;
            for(int i=1;i<10;i++)
                while(cnt2[i])
                {
                    b[ind]=i+'0'; ind--; cnt2[i]--;
                }
            puts(a); puts(b);
        }
        else
        {
            int cur=0,cnt1[10]={0},cnt2[10]={0},ind=n-1;
            for(int j=0;j<10;j++) cnt2[j]=cnt1[j]=cnt[j];
            /*while(cnt1[0])
            {
                a[ind]=b[ind]='0'; ind--;
                cnt1[0]--; cnt2[0]--;
            }*/
            if (cnt1[ii]&&cnt2[(10-ii)%10])
            {
                a[ind]=ii+'0'; b[ind]=(10-ii)%10+'0'; ind--;
                cnt1[ii]--,cnt2[(10-ii)%10]--;
            }
            for(int j=0;j<10;j++)
            {
                int k=min(cnt1[j],cnt2[9-j]);
                for(int i=0;i<k;i++)
                {
                    a[ind]=j+'0'; b[ind]=9-j+'0'; ind--;
                    cnt1[j]--; cnt2[9-j]--;
                }
            }
            int ind1=ind;
            int kk=min(cnt1[0],cnt2[0]);
            for(int i=0;i<kk;i++)
                a[n+i]=b[n+i]='0';
            cnt1[0]-=kk; cnt2[0]-=kk;
            for(int i=0;i<10;i++)
                while(cnt1[i])
                {
                    a[ind]=i+'0'; ind--; cnt1[i]--;
                }
            ind=ind1;
            for(int i=0;i<10;i++)
                while(cnt2[i])
                {
                    b[ind]=i+'0'; ind--; cnt2[i]--;
                }
            puts(a+kk); puts(b+kk);
        }
    } else return -1;
    return 0;
}