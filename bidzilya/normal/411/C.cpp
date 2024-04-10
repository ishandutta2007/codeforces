#include <string>
#include <cstdio>
using namespace std;

int a[4][2];

int win()
{
    if (a[0][0] > a[2][1] && a[1][1] > a[3][0] &&
        a[0][0] > a[3][1] && a[1][1] > a[2][0]) 
            return 1;
    if (a[2][1] > a[0][0] && a[3][0] > a[1][1]) return -1;
    if (a[3][1] > a[0][0] && a[2][0] > a[1][1]) return -1;
    return 0;
}

int main() 
{
  //  freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 2; ++j) 
            scanf("%d", &a[i][j]);
            
    bool draw = false;
    if (win() == 1) {
        printf("Team 1\n");
    } else {
        draw |= (win() == 0);
        swap(a[0], a[1]);
        if (win() == 1) {
            printf("Team 1\n");
        } else {
            draw |= (win() == 0);
            if (draw) {
                printf("Draw\n");
            } else {
                printf("Team 2\n");
            }
        }
    }
    return 0;
}