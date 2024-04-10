#include <cstdio>
#include <map>
#include <set>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <ctime>

#define ll long long

using namespace std;

int nums[100005],n,v[100005],A[100005];
map <int,int> f,s;

bool isOk(int a)
{
    if (a==0) return false;
    while(a)
    {
        if (a%10!=4&&a%10!=7) return false;
        a/=10;
    }
    return true;
}

vector <int> x,y;

pair <int,int> vv[100005];

int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&nums[i]);
        A[i]=v[i]=nums[i];
        vv[i]=make_pair(nums[i],i);
    }
    sort(v,v+n);
    int pos=-1,happy;
    for(int i=0;i<n;i++)
    {
        if (isOk(nums[i]))
        {
            pos=i;
            happy=nums[i];
            break;
        }
    }
    if (pos!=-1)
    {
        sort(vv,vv+n);
        for(int i=0;i<n;i++)
            nums[vv[i].second]=i+1;
        for(int i=0;i<n;i++)
        {
            v[i]=nums[i];
            f[v[i]]=i;
        }
        happy=v[pos];
        sort(v,v+n);
        for(int i=0;i<n;i++)
            s[i]=v[i];
        for(int i=0;i<n;i++)
        {
            int a=f[happy],b=i,pa=a,pb=b;
            if (a!=b)
            {
                swap(nums[a],nums[b]);
                swap(A[a],A[b]);
                x.push_back(a);
                y.push_back(b);
                f[nums[a]]=a; f[nums[b]]=b;
            }
            a=f[happy],b=f[s[i]];
            if (a!=b)
            {
                swap(nums[a],nums[b]);
                swap(A[a],A[b]);
                x.push_back(a);
                y.push_back(b);
                f[nums[a]]=a; f[nums[b]]=b;
            }
            if (pa!=pb&&min(pa,pb)==min(a,b)&&max(pa,pb)==max(a,b))
            {
                x.pop_back();
                y.pop_back();
                x.pop_back();
                y.pop_back();
            }
        }
    //  for(int i=0;i<n;i++)
    //      cout << nums[i] << "    ";
    //  cout << endl;
        printf("%d\n",x.size());
        for(int i=0;i<x.size();i++)
            printf("%d %d\n",x[i]+1,y[i]+1);
    }
    else
    {
        for(int i=1;i<n;i++)
            if (A[i-1]>A[i])
            {
                cout << -1 << endl;
                return 0;
            }
        cout << 0 << endl;
    }
//  for(int i=1;i<n;i++)
//      if (A[i-1]>A[i]) return -1;
//  if (x.size()>2*n) for(;;);
//  cout << 100 << endl << 4 << endl;
//  for(int i=1;i<100;i++)
//      cout << rand() << " ";
    return 0;
}