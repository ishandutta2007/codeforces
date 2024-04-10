#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    int h[n];
    int m=0,idx;
    for(int i=0;i<n;i++)
    {
        cin >> h[i];
        if(h[i]>m)
        {
            m=h[i];
            idx=i;
        }
    }
    int arr[n+1];
    int cur=0;
    for(int i=idx;;i=(i+1)%n)
    {
        arr[cur]=h[i];
        cur++;
        if(cur==n+1) break;
    }
    //for(int i=0;i<n+1;i++) cout << arr[i] << " ";
    //cout << endl;
    int a;
    long long c=0;
    stack<pair<int,int> > s;
    for(int i=0;i<n+1;i++)
    {
        a=arr[i];
        if(s.empty()) s.push({a,1});
        else
        {
            while(!s.empty()&&s.top().first<a)
            {
                c+=s.top().second;
                s.pop();
            }
            if(!s.empty()&&s.top().first>a) c++;
            if(!s.empty()&&s.top().first==a) c+=(s.top().second++)+(s.size()>1);
            else s.push({a,1});
        }
    }
    bool b[n+1];
    int cnt=0;
    for(int i=0;i<n+1;i++) b[i]=0;
    m=0;
    for(int i=1;i<n;i++)
    {
        m=max(m,arr[i]);
        if(arr[i]>=m) b[i]=1;
    }
    m=0;
    for(int i=n-1;i>=1;i--)
    {
        m=max(m,arr[i]);
        if(arr[i]>=m&&b[i]) cnt++;
    }
    cout << c-cnt-1 << endl;
    return 0;
}