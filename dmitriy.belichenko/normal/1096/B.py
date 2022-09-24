n = int(input())
s = input()
i = 0
j = 0
while(s[i] == s[0]):
    i+=1;
while(s[n - 1 - j] == s[n - 1]):
    j+=1;
ans = i + j + 1
if(s[0] == s[n - 1]):
    ans += i * j;
print(ans % 998244353)