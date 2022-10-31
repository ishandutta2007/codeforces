n = input()
s = sum(map(int, raw_input().split()))
print ["EASY", "HARD"][s > 0]