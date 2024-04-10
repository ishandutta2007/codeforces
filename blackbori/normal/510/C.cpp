#include <cstdio>
#include <cstring>

int N;
int Names[102][102];
char C[102];
int A[27][27];
int Ans[27];

int F(int s,int e,int i)
{
    int j,k;
    for(j=s; j<=e; j++) if(Names[j][i] != 0) break;
    if(j>e) return 0;
    for(j=s; j<=e; j++){
        k=j;
        while(Names[j+1][i] == Names[k][i] && j<e) j++;
        if(j!=e){
            A[Names[j+1][i]][Names[k][i]] = 1;
        }
        if(k<j) F(k,j,i+1);
    }

    return 0;
}

int main()
{
    scanf("%d",&N);
    int i,j,k;
    for(i=0; i<N; i++){
        scanf("%s",C);
        for(j=0; j<strlen(C); j++){
            Names[i][j] = C[j] - 'a' + 1;
        }
    }

    F(0,N-1,0);

    for(i=0; i<=26; i++){
        A[i][0] = 0;
        if(A[0][i]){
            printf("Impossible\n");
            return 0;
        }
    }

    for(i=0; i<26; i++){
        for(j=0; j<26; j++){
            for(k=0; k<=26; k++) if(A[j+1][k]) break;
            if(k==27) break;
        }
        if(j == 26){
            printf("Impossible\n");
            return 0;
        }
        Ans[i] = j;
        A[j+1][0] = 1;
        k=j;
        for(j=0; j<26; j++){
            if(A[j+1][k+1]){
                A[j+1][k+1] = 0;
            }
        }
    }

    for(i=0; i<26; i++) printf("%c",Ans[i]+'a');
    printf("\n");

    return 0;
}