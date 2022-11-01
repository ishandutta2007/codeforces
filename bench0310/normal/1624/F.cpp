#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int s=0;
    int k=0;
    int sum=0;
    auto q=[&](int x)->int
    {
        int nk=k;
        if(x>0)
        {
            cout << "+ " << x << endl;
            sum+=x;
            cin >> nk;
        }
        int t=nk-k;
        k=nk;
        return t;
    };
    int p=0;
    while((1<<(p+1))<n) p++;
    int all=0;
    for(int i=p;i>=0;i--)
    {
        int m=(1<<i)-s;
        s=0;
        int x=((m%n)+n)%n;
        int t=q(x);
        if(t==1)
        {
            s+=(1<<i);
            all+=(1<<i);
        }
    }
    int pos=(((n-1-((1<<(p+1))-1-all))%n)+n)%n;
    cout << "! " << pos+sum << "\n";
    return 0;
}