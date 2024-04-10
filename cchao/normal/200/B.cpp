#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int n;
    double sum = 0,tmp;
    cin >> n;
    for(int k=0;k<n;k++)
    {
        cin >> tmp;
        sum += tmp;
    }
    printf("%.10f",sum/n);
    return 0;
}