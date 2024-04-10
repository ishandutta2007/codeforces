#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N=(int) 2e5+7;
int n;
int a[N];
int b[N];

int main()
{
        ios::sync_with_stdio(0);
        cin.tie(0);


        cin>>n;
        for (int i=1;i<=n;i++)
                cin>>a[i];
        for (int i=1;i<=n;i++)
                cin>>b[i];
        int j=1,sol=n;
        for (int i=1;i<=n;i++)
        {
                while (j<=n&&b[j]!=a[i])
                        j++;
                if (j>n)
                        break;
                sol--;
        }
        cout<<sol<<"\n";
}