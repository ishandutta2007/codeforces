#include <iostream>
using namespace std;
int f(int x)
{
    int sum = 0;
    while(x > 0)
    {
        sum += x %10;
        x /=10;
    }
    return sum;
}
int main()
{
    int sum = 0;
    string s;
    cin >> s;
    if(s.length() == 1)
    {
        cout << 0 << endl;
        return 0;
    }
    for(int k = 0; k < s.length(); k++)
        sum += s[k] - '0';
    //cout << "Sum " << sum << endl;
    int cnt = 1;
    while(sum > 9)
    {
        cnt++;
        sum = f(sum);
    }
    cout << cnt << endl;
    return 0;
}