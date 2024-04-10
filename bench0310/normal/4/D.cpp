#include <bits/stdc++.h>

using namespace std;

bool comp(const tuple<int,int,int> &a,const tuple<int,int,int> &b)
{
    if(get<0>(a)!=get<0>(b)) return get<0>(a)>get<0>(b);
    else return get<1>(a)>get<1>(b);
}

int main()
{
    int n,w,h;
    cin >> n >> w >> h;
    vector<tuple<int,int,int> > v;
    int a,b;
    for(int i=0;i<n;i++)
    {
        cin >> a >> b;
        v.push_back(make_tuple(a,b,i));
    }
    sort(v.begin(),v.end(),comp);
    int arr[n][2];
    for(int i=0;i<n;i++) arr[i][0]=0,arr[i][1]=-1;
    int idx=-1,m=0;
    for(int o=0;o<n;o++)
    {
        if(get<0>(v[o])<=w||get<1>(v[o])<=h) continue;
        for(int i=0;i<o;i++)
        {
            if(get<0>(v[i])>get<0>(v[o])&&get<1>(v[i])>get<1>(v[o]))
            {
                if(arr[i][0]>arr[o][0])
                {
                    arr[o][0]=arr[i][0];
                    arr[o][1]=i;
                }
            }
        }
        arr[o][0]++;
        if(arr[o][0]>m)
        {
            m=arr[o][0];
            idx=o;
        }
    }
    if(idx==-1) cout << 0 << endl;
    else
    {
        cout << m << endl;
        while(idx!=-1)
        {
            cout << get<2>(v[idx])+1 << " ";
            idx=arr[idx][1];
        }
    }

    return 0;
}