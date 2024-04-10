#include <bits/stdc++.h>
#define endl '\n'
#define db(x) cout << x << endl;
using namespace std;
typedef long long ll;

vector<int> res;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,a,b;
    cin >> n >> a >> b;
    int cont=0;
    while((n-cont)%b && cont<=n)
        cont+=a;
//    db(cont)
    int r1=cont/a;
    int r2=(n-cont)/b;
    if(((r1*a)+(r2*b))==n && r2>=0)
    {
        for(int i=1;i<=r1;i++)
        {
            cout << a*i << ' ';
            for(int j=1;j<a;j++)
                cout << (a*(i-1))+j << ' ';
        }
        int sss=a*r1;
        for(int i=1;i<=r2;i++)
        {
            cout << b*i+sss << ' ';
            for(int j=1;j<b;j++)
            {
                cout << (b*(i-1))+j+sss;
                if(i!=r2 || j!=b-1)
                    cout << ' ';
            }
        }
    }
    else
        cout << -1;
    return 0;
}