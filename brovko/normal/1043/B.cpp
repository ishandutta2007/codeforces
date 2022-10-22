#include <iostream>
#include <vector>

using namespace std;
int n, a[1005], b[1005];
bool f;
vector <int> x;

int main()
{
    cin >> n;
    for(int i=1;i<=n;i++)
        cin >> a[i];
    for(int i=0;i<n;i++)
        b[i]=a[i+1]-a[i];
    for(int i=1;i<=n;i++)
    {
        f=true;
        for(int j=0;j<n;j++)
            if(b[j]!=b[j%i])
              f=false;
        if(f)
            x.push_back(i);
    }
    cout << x.size() << endl;
    for(int i=0;i<x.size();i++)
        cout << x[i] << ' ';
    return 0;
}