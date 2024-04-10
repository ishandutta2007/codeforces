#include <bits/stdc++.h>

using namespace std;

const int N=(int)2e5+7;

int n;
int v[N];
int f[N];
int j,mx;

void send(int i)
{
        if(1<=i-1 && v[i]!=v[i-1])
        {
                if(v[i-1]<v[i])
                {
                        v[i-1]=v[i];
                        cout<<"1 "<<i-1<<" "<<i<<"\n";
                }
                if(v[i-1]>v[i])
                {
                        v[i-1]=v[i];
                        cout<<"2 "<<i-1<<" "<<i<<"\n";
                }
                send(i-1);
        }
        if(i+1<=n && v[i]!=v[i+1])
        {
                if(v[i+1]<v[i])
                {
                        v[i+1]=v[i];
                        cout<<"1 "<<i+1<<" "<<i<<"\n";
                }
                if(v[i+1]>v[i])
                {
                        v[i+1]=v[i];
                        cout<<"2 "<<i+1<<" "<<i<<"\n";
                }
                send(i+1);
        }
}

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        cin>>n;
        for(int i=1;i<=n;i++)
        {
                cin>>v[i];
                f[v[i]]++;
                if(f[v[i]]-1==mx)
                {
                        mx++;
                        j=v[i];
                }
        }
        cout<<n-mx<<"\n";
        for(int i=1;i<=n;i++)
        {
                if(v[i]==j)
                {
                        send(i);
                }
        }
        return 0;
}