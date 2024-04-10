#include <iostream>
#include <cstring>

using namespace std;

string s1;
char s2[11];

bool palin(string s)
{
    int i;
    for(i=0; i<s.size(); i++){
        if(s[i] != s[s.size()-i-1]) return false;
    }
    return true;
}

int main()
{
    cin >> s1;
    int i, j;
    char l;
    bool f=false;
    for(int i=0; i<=s1.size(); i++){
        for(l='a'; l<='z'; l++){
            for(j=0; j<i; j++){
                s2[j] = s1[j];
            }
            s2[i] = l;
            for(j=i+1; j<=s1.size(); j++){
                s2[j] = s1[j-1];
            }
            if(palin(s2)){
                cout << s2 << endl;
                f = true;
                break;
            }
        }
        if(f) break;
    }

    if(!f) cout << "NA\n" << endl;

    return 0;
}