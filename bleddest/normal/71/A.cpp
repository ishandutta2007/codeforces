#include<string>
#include<iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        if(s.size() > 10)
        {
            cout << s[0] << s.size() - 2 << s.back() << endl;    
        }
        else
        {
            cout << s << endl;    
        }
    }
}