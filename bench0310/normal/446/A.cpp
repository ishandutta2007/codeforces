#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int> > v;

int len(int i)
{
    return v[i].second-v[i].first+1;
}

int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    int res=0;
    int last=0;
    scanf("%d",&arr[0]);
    for(int i=1;i<n;i++)
    {
        scanf("%d",&arr[i]);
        if(arr[i]<=arr[i-1])
        {
            v.push_back(make_pair(last,i-1));
            res=max(res,i-last+1);
            last=i;
        }
    }
    v.push_back(make_pair(last,n-1));
    res=max(res,n-last+1);
    //for(int i=0;i<(int)v.size();i++) cout << v[i].first << " " << v[i].second << endl;
    if(v.size()==1) printf("%d\n",n);
    else
    {
        for(int i=1;i<(int)v.size();i++)
        {
            if(len(i-1)>1&&len(i)>1)
            {
                if(arr[v[i].first+1]-arr[v[i-1].second]>1) res=max(res,len(i-1)+len(i));
                if(arr[v[i].first]-arr[v[i-1].second-1]>1) res=max(res,len(i-1)+len(i));
            }
        }
        for(int i=1;i<(int)v.size()-1;i++)
        {
            if(len(i)==1&&arr[v[i+1].first]-arr[v[i-1].second]>1) res=max(res,len(i-1)+1+len(i+1));
        }
        printf("%d\n",res);
    }
    return 0;
}