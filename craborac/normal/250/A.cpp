#include<cstdio>
#include<iostream>

using namespace std;

int answer[200];

int main()
{
    int n;
    cin >> n;
    int col1 = 0;
    int col2 = 0;
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if(a < 0)
        {
            if(col2 == 2)
            {
                answer[ans++] = col1;
                col1 = 1;
                col2 = 1;
            }
            else
            {
                col1++;
                col2++;
            }
        }
        else
            col1++;
    }
    if(col1 > 0)
    {
        answer[ans++] = col1;
    }
    cout << ans << "\n";
    for(int i = 0; i < ans; i++)
        cout << answer[i] << " ";

    return 0;
}