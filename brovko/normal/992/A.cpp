#include <iostream>

using namespace std;
int n, a, b[200001], k;

int main()
{
    cin >> n;
    k=0;
    for(int i=0;i<n;i++)
    {
        cin >> a;
        if(a!=0 && b[a+100000]==0)
            k++;
        b[a+100000]++;
    }
    cout << k;
    return 0;
}