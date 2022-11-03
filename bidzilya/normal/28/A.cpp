#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
#include <algorithm>
using namespace std;

typedef long long ll;

int n,m;
int x[500],y[500],ans[500];
queue<int> c[200001],
           a[200001];

bool check(int X)
{
    for (int i=0; i<=200000; i++)a[i]=c[i];
    for (int i=0; i<n; i++)
    {
        if (abs(i-X)%2){ans[i]=-1;continue;}
        int nx=(i+1)%n,ls=i-1;
        if (ls==-1)ls=n-1;
        int sum=abs(y[nx]-y[i])+abs(x[nx]-x[i])+
                abs(y[ls]-y[i])+abs(x[ls]-x[i]);
        if (a[sum].size() == 0)return false;
        ans[i]=a[sum].front()+1;
        a[sum].pop();
    }
    return true;
}

void show()
{
    cout << "YES" << endl;
    for (int i=0; i<n; i++)
        cout << ans[i] << " ";
    cout << endl;
}

int main()
{
    cin >> n >> m;
    for (int i=0; i<n; i++)cin>>x[i]>>y[i];
    for (int i=0; i<m; i++)
    {
        int l;
        cin >> l;
        c[l].push(i);
    }
    if (check(0))show();
        else if (check(1))show();
            else cout<<"NO"<<endl;
    return 0;
}