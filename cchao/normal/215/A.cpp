#include <iostream>
#include <map>
using namespace std;
int main()
{
    int n,m;
    cin >> n;
    int a[n];
    for(int k = 0 ; k< n ; k ++)
    {
        cin >> a[k];
    }
    map<int,int> mm;
    int t, ma = -1;
    cin >> m;
    for(int k = 0; k < m ; k++)
    {
        cin >> t;
        for(int j = 0; j < n; j++)
        {
            if(t % a[j] == 0)
            {
                int tmp = t/ a[j];
                //cout << "tmp" << tmp << endl;
                if(mm.count(tmp) <= 0) mm[tmp] = 1;
                else mm[tmp] ++;
                if(tmp > ma) ma = tmp;
            }
        }
    }
    //cout << "MA" << ma << endl;
    if(ma == -1) cout << 0 << endl;
    else cout << mm[ma] << endl;
    return 0;
}