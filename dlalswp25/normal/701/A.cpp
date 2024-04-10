#include <stdio.h>

bool picked[105];

int main()
{
    int n;
    int arr[105];
    int ans[60][2], cnt = 0, sum = 0;
    
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    
    for(int i = 0; i < n; i++)
    {
        if(picked[i])   continue;
        ans[cnt][0] = i + 1;
        picked[i] = true;
        for(int j = 0; j < n; j++)
        {
            if(picked[j])   continue;
            if(arr[i] + arr[j] == sum * 2 / n)
            {
                ans[cnt][1] = j + 1;
                picked[j] = true;
                break;
            }
        }
        cnt++;
    }
    
    for(int i = 0; i < cnt; i++)
    {
        printf("%d %d\n", ans[i][0], ans[i][1]);
    }
    return 0;
}