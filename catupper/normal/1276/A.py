def solve(string):
    n = len(string)
    i = 0
    ans = []
    while i < n:
        #twone
        if i + 4 < n and string[i:i+5] == "twone":
            ans.append(i+2 + 1)
            i += 5
        elif i + 2 < n and (string[i:i+3] == "one" or string[i:i+3] == "two"):
            ans.append(i+1 + 1)
            i += 3
        else:
            i += 1
    print(len(ans))
    print(" ".join(list(map(str, ans))))


for _ in range(int(input())):
    solve(input())