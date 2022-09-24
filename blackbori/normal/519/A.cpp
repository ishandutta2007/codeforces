#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <string>

using namespace std;

string s;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdin);

    int i,j;
    int White=0,Black=0;
    for(i=0; i<8; i++){
        cin >> s;
        for(j=0; j<8; j++){
            switch(s[j]){
            case 'Q':
                White+=9;
                break;
            case 'R':
                White+=5;
                break;
            case 'B':
                White+=3;
                break;
            case 'N':
                White+=3;
                break;
            case 'P':
                White+=1;
                break;
            case 'K':
                break;
            case 'q':
                Black+=9;
                break;
            case 'r':
                Black+=5;
                break;
            case 'b':
                Black+=3;
                break;
            case 'n':
                Black+=3;
                break;
            case 'p':
                Black+=1;
                break;
            case 'k':
                break;
            }
        }
    }

    if(White > Black) printf("White\n");
    else if(White < Black) printf("Black\n");
    else printf("Draw\n");


    return 0;
}