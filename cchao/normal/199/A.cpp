#include <iostream>
#include <set>
using namespace std;
int main()
{
    unsigned int fab[45];
    set<unsigned int> x;
    fab[0] = 0; fab[1] = 1;
    for(int k=2;k<45;k++)
    {
        fab[k] = fab[k-1] + fab[k-2];
    }
    long long int n;
    cin >> n;
    int i,j,k;
    for(i=0;j<45 && fab[i] <= n;i++)
    {
        for(j=0;j<45 && fab[i]+fab[j] <= n ; j++)
        {
            for(k=0;k<45 && fab[i] + fab[j] + fab[k] <=n;k++)
            {
                if(fab[i] + fab[j] + fab[k] == n)
                {
                    cout << fab[i] << ' ' << fab[j] << ' ' << fab[k] << endl;
                    return 0;
                }
            }
        }
    }
    cout << "I'm too stupid to solve this problem" << endl;
    return 0;
}