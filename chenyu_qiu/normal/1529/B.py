t = int(input())
for _ in range(t):
 n = int(input())
 a = list(int(x) for x in input().split())
 neg = [x for x in a if x <= 0]
 pos = [x for x in a if x > 0]
 neg.sort()
 ans = len(neg)
 if len(pos) > 0:
  ans += 1
  r = min(pos)
  for i in range(len(neg) - 1):
   if neg[i+1] - neg[i] < r:
    ans -= 1
    break
 print(ans)