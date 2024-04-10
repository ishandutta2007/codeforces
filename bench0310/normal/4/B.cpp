#include <iostream>

using namespace std;

int main()
{
    int d,sum;
    cin >> d >> sum;
    int low[d],high[d];
    int a=0,b=0;
    int res[d];
    for(int i=0;i<d;i++)
    {
        cin >> low[i] >> high[i];
        a+=low[i];
        b+=high[i];
        res[i]=low[i];
    }
    if(sum<a||sum>b) cout << "NO" << endl;
    else
    {
        cout << "YES" << endl;
        int idx=0;
        while(a<sum)
        {
            if(high[idx]-low[idx]>sum-a)
            {
                res[idx]+=sum-a;
                a=sum;
            }
            else
            {
                res[idx]=high[idx];
                a+=high[idx]-low[idx];
            }
            idx++;
        }
        for(int i=0;i<d;i++) cout << res[i] << " ";
        cout << endl;
    }
    return 0;
}