#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

vector<int> v;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    int a;
    int c=1;

    for(int i=0; i<n; i++)
    {
        cin>>a;
        v.push_back(a);
    }

    sort(v.begin(),v.end());

    for(int i=1; i<=n/2; i++)
    {
        if(v[i]==v[i-1])
            c++;
        else
            break;
    }

    if(c>n/2)
        db("Bob")
    else
        db("Alice")

            return 0;
}