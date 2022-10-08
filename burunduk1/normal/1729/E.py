for t in range(2,25):
	print(f"? 1 {t}"); x = int(input())
	print(f"? {t} 1"); y = int(input())
	if x != y: z = x + y
	if x == -1: z = t - 1; break
print("!", z)