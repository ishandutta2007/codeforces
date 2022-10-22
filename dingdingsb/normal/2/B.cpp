#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define MAX 1007

using namespace std;

int n,x;
int dp[2][MAX][MAX];
int p[2][MAX][MAX];

void print ( int x , int y , int k , int f  ) {
    if ( x == 1 && y == 1 );
    else if ( x == 1 ) print ( x , y-1 , k , 0);
    else if ( y == 1 ) print ( x-1 , y , k , 1);
    else {
        if ( dp[k][x][y] == dp[k][x-1][y] + p[k][x][y] )
            print ( x-1 , y , k , 1 );
        else print ( x , y-1 , k , 0);
    }
    if ( f == 3 ) return;
    printf ( "%c" , f?'D':'R' );
}

int main ( ) {
    while ( ~scanf ( "%d" , &n ) ) {
        int flag = 0,a,b;
        for ( int i = 1 ; i <= n ; i++ )
            for ( int j = 1 ; j <= n ; j++ ) {
                scanf ( "%d" , &x );
                if ( !x ) {
                    flag = 1;
                    p[0][i][j]++;
                    p[1][i][j]++;
                    a = i , b = j;
                    continue;
                }
                while ( x%2 == 0 ) {
                    p[0][i][j]++;
                    x /= 2;
                }
                while ( x%5 == 0 ) {
                    p[1][i][j]++;
                    x /= 5;
                }
            }
        memset ( dp , 0x3f , sizeof ( dp ) );
        for ( int k = 0 ; k < 2 ; k++ )
            for ( int i = 1 ; i <= n ; i++ )
                for ( int j = 1 ; j <= n ; j++ ) {
                    if ( i-1 )
                        dp[k][i][j] = min ( dp[k][i][j] , dp[k][i-1][j] );
                    if ( j-1 )
                        dp[k][i][j] = min ( dp[k][i][j] , dp[k][i][j-1] );
                    if ( i == j && i == 1 )
                        dp[k][i][j] = 0;
                    dp[k][i][j] +=  p[k][i][j];
                }
        int ans = min ( dp[0][n][n] , dp[1][n][n] );
        if ( ans > 1 && flag ) {
            puts ( "1" );
            for ( int i = 1 ; i < a ; i++ )
                printf ( "%c" , 'D' );
            for ( int j = 1 ; j < b ; j++ )
                printf ( "%c" , 'R' );
            for ( int i = a ; i < n ; i++ )
                printf ( "%c" , 'D' );
            for ( int j = b ; j < n ; j++ )
                printf ( "%c" , 'R' );
            puts ( "" );
            continue;
        }
        printf ( "%d\n" , ans );
        if ( dp[0][n][n] < dp[1][n][n] )
            print ( n , n , 0 , 3 );
        else print ( n , n , 1 , 3 );
        puts ( "" );
    }
}