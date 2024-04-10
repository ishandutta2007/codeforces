#include <cstdio>
#include <cstring>

int n;
char s[128];
long long dp[3][128][3];

long long getDP( int fi, int pos, int la )
{
    if ( dp[fi][pos][la] != -1 ) return dp[fi][pos][la];

    if ( ( pos == n-1 ) && ( fi == 1 ) )
    {
        return 1;
    }

    if ( pos >= n )
    {
        if ( fi != 2 )
            return 1-fi;
        return 1;
    }

    dp[fi][pos][la] = 0;
    if ( ( pos == 0 ) && ( fi == 1 ) )
    {
            if ( ( s[0] == 'A' ) && ( s[n-1] == 'B' ) )
            {
                dp[fi][pos][la] = getDP( fi, pos+1, 1 );
            }
        return dp[fi][pos][la];
    }

    if ( s[pos] == 'A' )
    {
        //put Ac;
        if ( ( pos != n-1 ) || ( fi != 2 ) )
        {
            dp[fi][pos][la] = getDP( fi, pos+1, 0 );
        }
    }
    else
    {
        if ( s[pos+1] == 'A' )
        {
            if ( ( pos != n-1 ) || ( fi != 2 ) )
            {
                //put AB;
                dp[fi][pos][la] = getDP( fi, pos+2, 1 );
            }
        }
        if ( la == 1 )
        {
            //put Bc;
            if ( pos != 0 )
                dp[fi][pos][la] += getDP( fi, pos+1, 1 );
            else
                dp[fi][pos][la] += getDP( 2, pos+1, 1 );
        }
    }
    return dp[fi][pos][la];
}

int main()
{
    scanf( "%s", s );
    n = strlen( s );

    memset( dp, -1, sizeof( dp ) );

    printf( "%I64d\n", getDP( 0, 0, 1 ) + getDP( 1, 0, 1  ) );
    return 0;
}