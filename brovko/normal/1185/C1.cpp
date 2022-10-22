#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, m, a[100], s, k, j, s1;
vector <int> v;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i=0;i<n;i++)
        cin >> a[i];
    for(int i=0;i<n;i++)
    {
        v.push_back(a[i]);
        sort(v.begin(), v.end());
        s+=a[i];
        s1=s;
        j=i;
        k=0;
        while(s1>m)
        {
            if(v[j]!=a[i] || (v[j]>0 && v[j]==v[j-1]))
            {
                k++;
                s1=s1-v[j];
            }
            j--;
        }
        cout << k << ' ';
    }
    return 0;
}