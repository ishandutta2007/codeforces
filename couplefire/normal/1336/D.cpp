#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    scanf("%d", &n);
    int straight[n+1];
    int triplets[n+1];
    int deltastraight[n];
    int deltatriplets[n];
    scanf("%d %d", &triplets[n], &straight[n]);

    for(int i = n-1; i >= 0; i--){
        int index = i;
        if(i <= 2){
            index = i % 2 + 1;
        }

        printf("+ %d\n", index);
        fflush(stdout);
        scanf("%d %d", &triplets[i], &straight[i]);
        deltatriplets[i] = triplets[i]-triplets[i+1];
        deltastraight[i] = straight[i]-straight[i+1];
    }
    
    int a[n+1];
    a[1] = sqrt(deltatriplets[0]*2);
    a[3] = deltastraight[0]-deltastraight[2]-1;
    a[2] = deltastraight[2]/(a[3]+1);
    a[4] = deltastraight[1]/(a[3]+1)-a[1]-2;
    for(int i = 5; i <= n; i++){
        a[i] = (deltastraight[i-2]-a[i-3]*(a[i-1]+1)-a[i-3]*a[i-4])/(a[i-1]+1)-1;
    }
    printf("!");a[n]++;
    for(int i = 1; i <= n; i++)printf(" %d", a[i]);
}