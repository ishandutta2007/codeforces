#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <math.h>
#include <fstream>
using namespace std;
map <char, char> mymap;
int main(){
    string s1, s2;
    cin >> s1 >> s2;
    for (int i=0;i<s1.size();i++){
        char a = s1[i];
        char b = s2[i];
        if (!mymap.count(a)){
            mymap[a] = b;
        }
        else{
            if (mymap[a] != b){
                cout << -1 << endl;
                return 0;
            }
        }
         if (!mymap.count(b)){
            mymap[b] = a;
        }
        else{
            if (mymap[b] != a){
                cout << -1 << endl;
                return 0;
            }
        }
    }
    char data [26] = {'a', 'b', 'c', 'd','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    int counter = 0;
    for (int i=0;i<26;i++){
        if (mymap.count(data[i])){
            if (mymap[data[i]] != data[i]){
                counter ++;
            }
        }
    }
    cout << counter / 2 << endl;
    for (int i=0;i<26;i++){
        if (mymap.count(data[i])){
            if (mymap[data[i]] != data[i] & mymap[mymap[data[i]]] != '&'){
                cout << data[i] << " " << mymap[data[i]] << endl;
                mymap[data[i]] = '&';
            }
        }
    }
    return 0;
    
}