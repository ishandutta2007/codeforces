#include <bits/stdc++.h>

using namespace std;

char first, second, third;
int horz, ver = 0;
string flag[100];
int horflag, verflag = 0;
int rows, cols;
    
int main() {
    cin >> rows >> cols;
    for(int i = 0; i < rows; i++) cin >> flag[i]; 
    if (rows % 3 == 0) horz = 1;
    if (cols % 3 == 0) ver = 1;
    
    if (horz == 1){
        first = flag[0][0];
        second = flag[rows/3][0];
        third = flag[rows/3 * 2][0];
        if (((first == 'R') || (first == 'G') || (first == 'B')) && ((second == 'R') || (second == 'G') || (second == 'B')) && ((third == 'R') || (third == 'G') || (third == 'B')) && ((first!=second) && (first!=third) && (second!=third))){
            for(int i = 0; i < rows/3; i++) for(int j = 0; j < cols; j++) if(flag[i][j] !=first) horflag = 1;
            for(int i = rows/3; i < rows/3 * 2; i++) for(int j = 0; j < cols; j++) if(flag[i][j] !=second) horflag = 1;
            for(int i = rows/3 * 2; i < rows; i++) for(int j = 0; j < cols; j++) if(flag[i][j] !=third) horflag = 1;
        } else horflag = 1;
    }
    
    if(ver == 1){
        first = flag[0][0];
        second = flag[0][cols/3];
        third = flag[0][cols/3 * 2];
        if((first == 'R' || first == 'G' || first == 'B') && (second == 'R' || second == 'G' || second == 'B') && (third == 'R' || third == 'G' || third == 'B') && first!=second && first!=third && second!=third){
            for(int i = 0; i < cols/3; i++) for(int j = 0; j < rows; j++) if(flag[j][i] != first) verflag = 1;
            for(int i = cols/3; i < cols/3 * 2; i++) for(int j = 0; j < rows; j++) if(flag[j][i] != second) verflag = 1;
            for(int i = cols/3 * 2; i < cols; i++) for(int j = 0; j < rows; j++) if(flag[j][i] != third) verflag = 1;
        }
        else verflag = 1;
    }
    
    if(horz == 0 && ver == 0) cout << "NO" ;
    else if(horz == 1 && horflag == 0) cout << "YES";
    else if(ver == 1 && verflag == 0) cout << "YES";
    else cout << "NO";
}