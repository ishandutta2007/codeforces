#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;
int main(){
    string s;
    cin>>s;
    if(s[0]>96) s[0]-=32;
    cout<<s;
    return 0;
}