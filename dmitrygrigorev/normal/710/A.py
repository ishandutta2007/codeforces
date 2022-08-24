string =input()
line = "abcdefgh"
a = line.find(string[0]) + 1
b = int(string[1])
if (a, b) in [(1, 1), (8, 8), (1, 8), (8, 1)]:
    print(3)
elif a in [1, 8] or b in [1, 8]:
    print(5)
else:
    print(8)