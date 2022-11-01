#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e6+3;
const ll INF =2e15;

double GetHeight(double dBottom, double dHeight)
{

    double dLength = sqrt(dBottom*dBottom + dHeight*dHeight);
    return (dBottom*dHeight / dLength);
}
int main()
{
    double dHeight, dWidth, dRadius;
    cin >> dRadius;
    for(dWidth = 1; dWidth <= 10; dWidth++){
        for(dHeight = 1; dHeight <= 10; dHeight++){

            if(abs(dRadius - GetHeight(dWidth / 2, dHeight))<=1e-6)
            {
                cout << dWidth << ' ' << dHeight << endl; 
                return 0;
            }
        }
    }
    return 0;
}