#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <list>
#include <iostream>
using namespace std;
list<int> l;
list<int>::iterator it = l.begin();
string s;
int main(){
    cin >> s;
    int no=1;
    l.insert(it, no);
    --it;
    for(int i = 0; i < s.length()-1; ++i){
        ++no;
        if(s[i] == 'l'){
            l.insert(it, no);
            --it;
        }
        else{
            ++it;
            l.insert(it, no);
            --it;
        }
    }
    for(it = l.begin(); it != l.end(); ++it)
        cout << *it << endl;
    return 0;
}