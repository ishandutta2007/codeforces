#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    string str = "";
    cin >> n;
    int i;
    for (i=n; i>0; i--) {
        if ((n-i)%2==0) {str = str + "I hate ";}
        else {str = str + "I love ";};
        if (i>1) {str = str + "that ";}
        else {str = str + "it";};
    }
    cout << str << endl;
    return 0;
}