n = int(raw_input())
res = 1
for i in range(5):
    res = res * (n-i) * (n-i) / (i+1)
print res