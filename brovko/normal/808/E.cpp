#include <bits/stdc++.h>

using namespace std;
long long n, m, w[100005], c[100005], Max, ps0[200005], ps1[200005], s3;
vector <long long> v1, v2, v3, v20, v21;
bool comp(int x, int y)
{
    return x>y;
}

int main()
{
    cin >> n >> m;
    for(int i=0;i<n;i++)
        cin >> w[i] >> c[i];
    for(int i=0;i<n;i++)
    {
        if(w[i]==1)
            v1.push_back(c[i]);
        if(w[i]==2)
            v2.push_back(c[i]);
        if(w[i]==3)
            v3.push_back(c[i]);
    }
    sort(v1.begin(), v1.end(), comp);
    sort(v2.begin(), v2.end(), comp);
    sort(v3.begin(), v3.end(), comp);
    for(int i=0;i<v2.size();i++)
    {
        v20.push_back(v2[i]);;
        v21.push_back(v2[i]);
    }
    for(int i=0;i<int(v1.size())-1;i+=2)
        v20.push_back(v1[i]+v1[i+1]);
    for(int i=1;i<int(v1.size())-1;i+=2)
        v21.push_back(v1[i]+v1[i+1]);
    sort(v20.begin(), v20.end(), comp);
    sort(v21.begin(), v21.end(), comp);
    for(int i=0;i<int(v20.size());i++)
        ps0[i+1]=ps0[i]+v20[i];
    for(int i=0;i<int(v21.size());i++)
        ps1[i+1]=ps1[i]+v21[i];
    for(int i=0;i<=int(v3.size());i++)
    {
        if(i>0)
        s3+=v3[i-1];
        if(m>=3*i)
        Max=max(Max, s3+ps0[min((long long) v20.size(), (m-3*i)/2)]);
        if(m>=3*i+1 && int(v1.size()))
        Max=max(Max, s3+v1[0]+ps1[min((long long)v21.size(), (m-3*i-1)/2)]);
    }
    cout << Max;
    return 0;
}