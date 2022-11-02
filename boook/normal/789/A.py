n , m = map(int , input().split())
a = list(map(int , input().split()))
ans = 0
for i in a :
	ans += i // m if i % m == 0 else i // m + 1
print(int((ans + 1) / 2))