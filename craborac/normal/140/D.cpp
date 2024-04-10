#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int mas[200];

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> mas[i];
    sort(mas, mas + n);
    int sum = 10;
    int ans1 = 0;
    int ans2 = 0;
    for(int i = 0; i < n; i++)
    {
        sum += mas[i];
        if(sum > 720)
        {
            cout << ans1 << " " << ans2;
            return 0;
        }
        else
        {
            ans1++;
            if(sum > 360)
                ans2 += sum - 360;
        }
    }
    cout << ans1 << " " << ans2;

    return 0;
}