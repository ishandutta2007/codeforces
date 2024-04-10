#include<string>
#include<iostream>
#include<set>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    do
    {
        int pos = s.find("ogo");
        if(pos == string::npos)
            break;
        for(int i = pos; i <= pos + 2; i++)
            s[i] = '*'; 
        while(s.substr(pos + 3, 2) == "go")
        {
            s.erase(pos + 3, 2);
        }
    }
    while(true);
    cout << s << endl;
}