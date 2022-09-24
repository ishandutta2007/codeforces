#include <iostream>
#include <vector>
using namespace std;
long long int d[10001];
int main()
{
    int n, k;
    cin >> n >> k;
    int a;
    for(int i = 0; i < n; i++)
    {
        cin >> a;
        d[a]++;
    }
    vector <int> c;
    for(int i = 0; i < 32768; i++)
    {
        int cou = 0, h = i;
        for(int j = 0; j < 20; j++)
        {
            cou += h % 2;
            h = h/2;
        }
        if(cou == k)
            c.push_back(i);
    }
    //for(int i = 0; i < c.size(); i++)
        //cout << c[i] << " ";
    long long int ans = 0;
    if (k == 0)
    {
        for(int i = 0; i <= 10000; i++)
        {
            ans += d[i]*(d[i]-1)/2;
        }
        cout << ans;
        return 0;
    }

    for(int i = 0; i < 10001; i++)
    {
        for(int j = 0; j < c.size(); j++)
        {
           int b = i^c[j];
           if(b <= 10000)
                ans += d[i]*d[b];
        }
    }
    cout << ans/2;
    return 0;
}